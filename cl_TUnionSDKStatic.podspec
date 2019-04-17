Pod::Spec.new do |s|

  s.name         = "cl_TUnionSDKStatic"
  s.version      = "0.1.11"
  s.summary      = "淘宝客SDK"
  s.description  = "淘宝客SDK"

  s.homepage     = "https://github.com/Jeffrey-huang/cl_tunionsdkstatic"
  s.license      = { :type => "CHELUN", :file => "LICENSE" }

  s.author       = { 'lizhengxing' => 'lizhengxing@chelun.com' }
  s.source       = { :git => "https://github.com/Jeffrey-huang/cl_tunionsdkstatic.git", :tag => s.version.to_s }
  s.requires_arc = true
  s.platform     = :ios, "8.0"

  
#   s.subspec 'Auth' do |auth|
#   
#   	auth.source_files = 'AlibabaAuthSDK.framework/Headers/**.h'
#   	auth.public_header_files = 'AlibabaAuthSDK.framework/Headers/**.h'
#   	
#   	auth.vendored_frameworks = 'AlibabaAuthSDK.framework'
#     
#     auth.resources = 'AlibabaAuthSDK.bundle'
#   end
#   
#   s.subspec 'Link' do |link|
#   
#   	link.source_files = 'TBAppLinkSDK.framework/Headers/**.h'
# 	link.public_header_files = 'TBAppLinkSDK.framework/Headers/**.h'
#   	
#   	link.vendored_frameworks = 'TBAppLinkSDK.framework'
#     
#   end
#   
#   s.subspec 'Union' do |union|
#   
#   	union.source_files = 'TUnionSDKStatic.framework/Headers/**.h'
#   	union.public_header_files = 'TUnionSDKStatic.framework/Headers/**.h'
#   	
#   	union.vendored_frameworks = 'TUnionSDKStatic.framework'
#     
#     union.resources = 'AlibabaAuthSDK.bundle'
#     
#   end
  
  s.vendored_frameworks = 'AlibabaAuthSDK.framework', 'TBAppLinkSDK.framework','TUnionSDKStatic.framework'
  s.resources = 'AlibabaAuthSDK.bundle'

  #s.libraries = 'iconv', 'c++'
  #s.frameworks = 'UIKit'
  #s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64 armv7' }

end
