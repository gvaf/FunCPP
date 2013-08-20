# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "precise64"
  config.vm.box_url = "http://files.vagrantup.com/precise64.box"

  config.vm.synced_folder ".", "/funcpp"

  config.vm.define "funcpp" do |funcpp|

  config.vm.provision :chef_solo do |chef|
     chef.cookbooks_path = "./chef/cookbooks"
     chef.roles_path     = "./chef/roles"
     chef.data_bags_path = "./chef/data_bags"
     chef.add_role "develop"
  end


end

end
