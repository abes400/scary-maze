CC 						= gcc
STD 					= 17

EXEC_NAME_ASSET			= assetgen
TEMP_ASSETGEN_DIR		= _temp_do_not_ship_can_delete
TEMP_ASSETGEN_SRC		= source
TEMP_ASSETGEN_DST		= temp_asset_headers
CUSTOM_ASSETS_DIR		= custom_assets
C_SRCS_ASSET			= project/src/assetgen.c

INCLUDE_DIRS 			= project/include
LIB_INCLUDE_DIRS		= project/lib/include

C_SRCS 					= $(filter-out $(C_SRCS_ASSET), $(wildcard project/src/*.c))

LINKED_LIB_DIR			= project/lib/bin/

EXEC_NAME				= The\ Maze




# windows specific opts
WINDOWS_LINKED_LIBS 	= -lopengl32 -lgdi32 -lwinmm -luuid -lole32
WINDOWS_RAYLIB_LINKED 	= libraylib_windows_x64.a

win:
	clear
	mkdir -p $(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_SRC)
	cp -r $(CUSTOM_ASSETS_DIR)/* 	$(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_SRC)
	cp -r project/assets/* 			$(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_SRC)

#	Compiling the asset generation program
	@echo [ INFO ] Compiling the Asset Generation Program...
	$(CC) -std=c$(STD) 													\
	$(C_SRCS_ASSET) 													\
	-I$(LIB_INCLUDE_DIRS) 												\
	$(LINKED_LIB_DIR)$(WINDOWS_RAYLIB_LINKED) $(WINDOWS_LINKED_LIBS) 	\
	-o $(TEMP_ASSETGEN_DIR)/$(EXEC_NAME_ASSET)							\
	-static
	@echo [ INFO ] Asset Generation Program compiled successfylly.

#	Running the assetgen program and generating the asset headers
	@echo [ INFO ] Running the Asset Generation Program...
	cd $(TEMP_ASSETGEN_DIR) && ./$(EXEC_NAME_ASSET)
	@echo [ INFO ] Assets generated successfully.

#	Compiling the main program
	@echo [ INFO ] Compiling the main program...
	mkdir -p _dist/
	$(CC) -std=c$(STD) 													\
	$(C_SRCS) 															\
	-I$(INCLUDE_DIRS) 													\
	-I$(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_DST) 						\
	-I$(LIB_INCLUDE_DIRS) 												\
	$(LINKED_LIB_DIR)$(WINDOWS_RAYLIB_LINKED) $(WINDOWS_LINKED_LIBS) 	\
	-o _dist/$(EXEC_NAME)												\
	-static																\
    -mwindows
	@echo [ INFO ] Main program compiled successfully.

#	Removing the temp dir
	@echo [ INFO ] Removing the temporary files...
	rm -rf $(TEMP_ASSETGEN_DIR)

	@echo [ INFO ] WINDOWS BUILD SUCCEEDED. Output located at _dist/
	start .\_dist\

# macOS specific opts
MACOS_ARCHS			= -arch x86_64 -arch arm64
MACOS_LINKED_LIBS 	= -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
MACOS_RAYLIB_LINKED = libraylib_macosx_uni.a

osx:
	clear
	mkdir -p $(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_SRC)
	cp -r $(CUSTOM_ASSETS_DIR)/* 	$(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_SRC)
	cp -r project/assets/* 			$(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_SRC)

#	Compiling the asset generation program
	@echo [ INFO ] Compiling the Asset Generation Program...
	$(CC) -std=c$(STD) 												\
	$(MACOS_ARCHS) 													\
	$(C_SRCS_ASSET) 												\
	-I$(LIB_INCLUDE_DIRS) 											\
	$(MACOS_LINKED_LIBS) $(LINKED_LIB_DIR)$(MACOS_RAYLIB_LINKED)	\
	-o $(TEMP_ASSETGEN_DIR)/$(EXEC_NAME_ASSET)
	@echo [ INFO ] Asset Generation Program compiled successfylly.

#	Running the assetgen program and generating the asset headers
	@echo [ INFO ] Running the Asset Generation Program...
	cd $(TEMP_ASSETGEN_DIR) && ./$(EXEC_NAME_ASSET)
	@echo [ INFO ] Assets generated successfully.

#	Compiling the main program
	@echo [ INFO ] Compiling the main program...
	mkdir -p _dist/
	$(CC) -std=c$(STD) 												\
	$(MACOS_ARCHS) 													\
	$(C_SRCS) 														\
	-I$(INCLUDE_DIRS) 												\
	-I$(TEMP_ASSETGEN_DIR)/$(TEMP_ASSETGEN_DST) 					\
	-I$(LIB_INCLUDE_DIRS) 											\
	$(MACOS_LINKED_LIBS) $(LINKED_LIB_DIR)$(MACOS_RAYLIB_LINKED)	\
	-o _dist/$(EXEC_NAME)
	@echo [ INFO ] Main program compiled successfully.

#	Remove the temp dir
	@echo [ INFO ] Removing the temporary files...
	rm -rf $(TEMP_ASSETGEN_DIR)

	@echo [ INFO ] MACOS BUILD SUCCEEDED. Output located at _dist/
	open ./_dist/


lipo: _dist/$(EXEC_NAME) $(LINKED_LIB_DIR)$(MACOS_RAYLIB_LINKED)
	lipo -info $(LINKED_LIB_DIR)$(MACOS_RAYLIB_LINKED)
	lipo -info _dist/$(EXEC_NAME)

clear: _dist
	rm -rf _dist
	@echo [ INFO ] OUTPUT FILES DELETED.

cleartemp: _temp_do_not_ship_can_delete
	rm -rf _temp_do_not_ship_can_delete
	@echo [ INFO ] TEMP ASSETGEN FILES DELETED.
