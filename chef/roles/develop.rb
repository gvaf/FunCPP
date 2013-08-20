name "develop"

default_attributes(
    "build_essential" => {
        "compiletime" => true
    }
)

run_list(
    "recipe[apt]",
    "recipe[build-essential]",
    "recipe[cmake]",
    "recipe[emacs]",
    "recipe[openssl]",
    "recipe[git]",
    "recipe[ntp]",
    "recipe[zip]",
    "recipe[curl]",
    "recipe[gcc11]",
    "recipe[boost]",
    "recipe[boost::source]"
)
