all:
	gcc -o i3-rocketlaunch main.c `pkg-config --libs --cflags i3ipc-glib-1.0`

install:
	install i3-rocketlaunch /usr/bin
