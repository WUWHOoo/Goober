# Goober the RoboGoose

A bipedal robot in the form of a goose made to wander around and quack all day long. The walking problem is part of the fun. Each leg combines three servos with a 5010 brushless motor and a printed cycloidal gearbox. I can change a joint or try a gait in MuJoCo before committing to another print.

![Goober's full mechanical assembly, rendered from the saved Fusion geometry](docs/images/assembly.png)

## Try Goober

1. Download and extract the [MuJoCo model](simulation/Goober-MuJoCo-legs.zip). Keep `goober.xml` beside its `meshes` folder.
2. Install the simulator with `python -m pip install mujoco==3.3.7`. From the extracted folder run `python -m mujoco.viewer --mjcf=goober.xml` to inspect the eight moving leg joints. The viewer opens the robot in its starting pose. A walking policy needs a controller.
3. To train a gait, open the [training notebook](simulation/Train-Goober-Gait.ipynb) in Google Colab on a CPU runtime. Run the cells in order and select the model ZIP and the [starting policy](simulation/Goober-PPO-printed.zip) together when prompted. The notebook compares policies by running walking trials on two simulated surfaces.

## Mechanical design

Open the [assembly archive](CAD/Goober.f3d) in Autodesk Fusion to inspect the torso, neck, beak, legs and actuator assemblies. The CAD includes motor, servo and encoder geometry. The carrier PCB is supplied separately in KiCad. The [actuator print files](CAD/Goober-Actuator-v3-STLs.zip) include the housings, cycloidal discs, output carrier and encoder shim. The [cycloidal drive STEP](CAD/Cyloidal%20Drive.step) is also available. Individual STEP exports for the other modeled parts are pending.

## Electronics

The two-layer carrier connects the STM32H723 controller, radio receiver, servos and two brushless motor drivers. The battery feeds the converter modules. The left and right leg-servo banks each have an 8.4 V supply, and a separate converter supplies 5 V.

![Top view of the routed Goober carrier board](docs/images/pcb.png)

![Goober power distribution and controller schematic](docs/images/PDB.svg)

Open [PDB.kicad_pro](PCB/PDB.kicad_pro) in KiCad 10 to inspect the schematic, copper and footprints. The [fabrication archive](PCB/gerbers.zip) contains both copper layers, masks, silkscreens, paste, outline and the drill file. The screw-terminal footprints are placeholders. Confirm the selected terminals and power-path current capacity before ordering the board.

The [design BOM](BOM.csv) lists PCB quantities and robot components. Catalog searches identify candidates where a purchased part number is unknown. Ownership, final hardware quantities and the purchase links still need confirmation.

## Firmware and build status

The [STM32 bring-up sketch](firmware/GooberBringup/GooberBringup.ino) reports controller uptime over serial. Select your STM32H723 board in Arduino IDE with the STM32duino core, enable USB CDC as the generic Serial port, and open Serial Monitor at 115200 baud. Send `?` for a status line. Test with the controller alone and the motor supplies disconnected.

This is a design-stage release. The bring-up sketch is untested on the robot. Walking trials run in simulation, and the physical walking firmware, finished-build photos and hardware demo video are pending.
