#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

#include "vroot.h"

int
main(int argc, char *argv[])
{
	Display *dpy;
	Window root;
	XWindowAttributes wa;
	GC g;
	XColor blackx, blacks, bluex, blues;
	Font f;

	dpy = XOpenDisplay(getenv("DISPLAY"));
	root = DefaultRootWindow(dpy);
	g = XCreateGC(dpy, root, 0, NULL);
	f = XLoadFont(dpy, "-*-helvetica-bold-r-*-*-20-*-*-*-*-*-*-*");

	XSetForeground(dpy, g,
			WhitePixelOfScreen(DefaultScreenOfDisplay(dpy)));

	XGetWindowAttributes(dpy, root, &wa);

	XAllocNamedColor(
		dpy,
		DefaultColormapOfScreen(DefaultScreenOfDisplay(dpy)),
		"black",
		&blacks, &blackx);

	XAllocNamedColor(dpy,
		DefaultColormapOfScreen(DefaultScreenOfDisplay(dpy)),
		"blue",
		&blues, &bluex);

	XSetFont(dpy, g, f);


	while (1) {
		int x = random() % wa.width - 25;
		int y = random() % wa.height;
		const char *text = "god is here";

		XSetForeground(dpy, g, blacks.pixel);
		XFillRectangle(dpy, root, g, x - 5, y - 20, 112, 40);
		XSetForeground(dpy, g, blues.pixel);
		XDrawString(dpy, root, g, x, y, text, strlen(text)); 
		XFlush(dpy);
		usleep(10);
	}

	XCloseDisplay(dpy);
	return 0;
}
