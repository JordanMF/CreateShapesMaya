# CreateShapesMaya Instructions

## Creating the project

1. Create a new folder called 'build'.
2. In Terminal (OSX) type "cmake -G "Your IDE goes here" -D MAYA_VERSION=20xx ../"
3. Now you can find the project file inside the build folder.

## Loading the plug-in

1. Open Maya and go to 'Windows - Settings/Preferences - Plug-in Manager'.
2. Browse to the plug-in in the file explorer and load it.
	* The plug-in will have a different file extension depending on your OS (Windows - .mll, Mac - .bundle, Linux - .so).

## Creating the plug-in

1. To create the plugin, open the Script Editor and type:
	* (If using Python) "import maya.cmds as cmds 
	node = cmds.createNode('reflection')"
	* (If using MEL) "createNode reflection"
2. Once created, a locator will appear at the origin of the viewport (0, 0, 0) along with the shapes.
3. From there, the locator can be translated/rotated/scaled.
