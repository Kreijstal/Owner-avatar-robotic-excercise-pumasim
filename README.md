# RBO Lab's Puma simulator based on Stanford's Puma simulator

- This directory contains the precompiled simulator

## Installing the simulator on Ubuntu 20.04

Due to its dependencies, it currently works with Ubuntu 20.04

* Install dependencies
    ```bash
    sudo apt-get install libnewmat10-dev libqhull-dev libopencv-dev cmake libsoil1 libglew2.1
    ```
* run the install script to install the simulator in `/opt/pumasim` and provide the command `pumasim`
    ```bash
    ./install.sh 
    ```

## Running the simulator

- You can call the simulator anywhere using the command `pumasim`
- When started, the simulator looks for two libraries: controller library `libcontrolDLL.so` (mandatory) and the vision loop `libcv_main.so` (optional).
- The simulator first checks the current directory for these libraries and loads them. 
    - If there is NO library file in the current directory, the simulator loads the example `libcontrolDLL.so` provided in `/opt/pumasim` instead.

## Compiling `libcontrolDLL.so`

- Check file `README.md` for `controlDLL` in the exercise packages (the code to create the controller and vision loop libraries).
- Each exercise is set using `cmake` and compiled using `make`.
- The compilation system setup follows the canonical use of `cmake`:

```bash
cd A1  # change into the exercise 1 directory
mkdir build && cd build
cmake ..
make
```

To load the controller library into the `pumasimulator`, simply run `pumasim` in the `build/` directory
