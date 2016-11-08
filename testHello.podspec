Pod::Spec.new do |spec|
  spec.name         = 'testHello'
  spec.version      = '0.0.1'
  spec.license      = { :type => 'BSD' }
  spec.homepage     = 'https://github.com/GuillaumeHighCo/testHello'
  spec.authors      = { 'Guillaume Martinez' => 'g.martinez@highconnexion.com' }
  spec.summary      = 'testHello deployement via CocoaPod'
  spec.source       = { :git => 'https://github.com/GuillaumeHighCo/testHello.git', :tag => '0.0.1' }
#spec.source_files = 'Reachability.{h,m}'
  spec.vendored_libraries = "frameworks/*"
end
