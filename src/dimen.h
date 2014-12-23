#ifdef __DIMEN_H__
#define __DIMEN_H__

struct tai {
	u32 O;
};

struct ji {
	u32 P;
};

/*
 * dimen describe
 */
struct dimen {
	u32 dimen;
	struct tai *tai;
	struct ji  *ji;
};

int dimen_create(struct dimen *dimen, u32 complexity);
void dimen_release(struct dimen *dimen);

#endif
