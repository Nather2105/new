APP_NAME = myApp
BUILD_DIR = ./bin
CPP_FILES = ./*.cpp

APP_DEFINES:=
APP_INCLUDES:= -I./GLFW/include/GLFW/  -framework OpenGL -framework IOKit
APP_LINKERS:= -L./GLFW/lib -lglfw3

build:
	clang $(CPP_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES) $(APP_LINKERS)