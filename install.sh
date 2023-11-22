#!/bin/bash

echo "Installing the simulator into /opt/pumasim"
# Clean up previous installed files
sudo rm -r /opt/pumasim 2> /dev/null
sudo cp -r pumasim /opt

echo "Create a symbolic link to the binary file"
sudo ln -sf /opt/pumasim/pumasim /usr/local/bin/pumasim 2> /dev/null
