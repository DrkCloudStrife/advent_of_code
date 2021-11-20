# frozen_string_literal: true

source "https://rubygems.org"

git_source(:github) {|repo_name| "https://github.com/#{repo_name}" }

%w[rspec rspec-core rspec-expectations rspec-mocks rspec-support].each do |lib|
  gem lib, :git => "https://github.com/rspec/#{lib}.git", :branch => 'main'
end
gem 'byebug', require: false
