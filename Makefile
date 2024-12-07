default:
	gcc ./src/main.c -L./libs -lraylib -lwinmm -lgdi32 -lopengl32 -I./include