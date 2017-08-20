# Omniauth-facebook 사용하기
### 1. gem 설치
```ruby
# gemfile
gem 'omniauth-facebook'
```

```
$ bundle install
```

### 2. User model 변경
```
$ rails g migration AddOmniauthToUsers provider:string uid:string
$ rake db:migrate
```

### 3. Facebook App id, secret key 환경변수 설정
```ruby
# config/initializers/devise.rb
config.omniauth :facebook, ENV["FB_APP_ID"], ENV["FB_APP_SECRET"]
```

```
$ echo "export APP_ID=APP_ID" >> ~/.bashrc
$ echo "export APP_SECRET=APP_SECRET" >> ~/.bashrc
$ source ~/.bashrc
$ env | grep APP
```

### 4. user model - omniauth 연결
```ruby
devise :database_authenticatable, :registerable,
       :recoverable, :rememberable, :trackable, :validatable,
       :omniauthable, :omniauth_providers => [:facebook]
```

### 5. devise routes 지정
```ruby
devise_for :users, :controllers => { :omniauth_callbacks => "users/omniauth_callbacks" }
```

### 6. omniauth callback 지정
```ruby
# app/controllers/users/omniauth_callbacks_controller.rb
class Users::OmniauthCallbacksController < Devise::OmniauthCallbacksController
  def facebook
    # You need to implement the method below in your model (e.g. app/models/user.rb)
    @user = User.from_omniauth(request.env["omniauth.auth"])

    if @user.persisted?
      sign_in_and_redirect @user, :event => :authentication #this will throw if @user is not activated
      set_flash_message(:notice, :success, :kind => "Facebook") if is_navigational_format?
    else
      session["devise.facebook_data"] = request.env["omniauth.auth"]
      redirect_to new_user_registration_url
    end
  end

  def failure
    redirect_to root_path
  end
end
```

### 7. facebook 계정정보 가져오기
```ruby
# app/models/user.rb
def self.from_omniauth(auth)
  where(provider: auth.provider, uid: auth.uid).first_or_create do |user|
    user.email = auth.info.email
    user.password = Devise.friendly_token[0,20]
    user.name = auth.info.name   # assuming the user model has a name
    user.image = auth.info.image # assuming the user model has an image
    # If you are using confirmable and the provider(s) you use validate emails, 
    # uncomment the line below to skip the confirmation emails.
    # user.skip_confirmation!
  end
end

def self.new_with_session(params, session)
  super.tap do |user|
    if data = session["devise.facebook_data"] && session["devise.facebook_data"]["extra"]["raw_info"]
      user.email = data["email"] if user.email.blank?
    end
  end
end
```

### 8. Login, Sign out
```ruby
# Login
<%= link_to "Sign in with Facebook", user_facebook_omniauth_authorize_path %>

# Logout Links
# config/routes.rb
devise_scope :user do
  delete 'sign_out', :to => 'devise/sessions#destroy', :as => :destroy_user_session
end
```