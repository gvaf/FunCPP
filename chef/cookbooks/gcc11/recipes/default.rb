bash "install_gcc" do
  user "root"
  cwd "/tmp"
  code <<-EOH
  apt-get update -y
  sudo apt-get install python-software-properties -y
  add-apt-repository ppa:ubuntu-toolchain-r/test -y
  apt-get update -y
  update-alternatives --remove-all gcc
  update-alternatives --remove-all g++ 
  apt-get install gcc-4.8  -y
  apt-get install g++-4.8  -y
  update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 20
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 20
  EOH
end
