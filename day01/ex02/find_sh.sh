#/bin/sh
basename $(find . -name "*.sh") | sed 's/.\{3\}$//'
