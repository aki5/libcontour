
enum {
	Fid = 0x7f,
//	Fset = 0x0f,
	Fcont = 0x80,
};

typedef struct Contour Contour;

struct Contour {
	uint8_t *img;
	int off;
	int end;
	int moore[16];
	int16_t width;
	int16_t height;
	int16_t stride;
};

void initcontour(Contour *cp, uint8_t *img, int width, int height, int stride);
int nextcontour(Contour *cp, int16_t *pt, int apt, int fillrule, int *idp);
void resetcontour(Contour *cp);

int fitpoly(int *poly, int apoly, int16_t *pt, int npt, int32_t dstthr);
