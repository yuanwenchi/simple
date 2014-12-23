/*
 * 1.hold
 */

struct frame_simple {
	u32 place;
};

struct frame_complex {
	u32 cmpl_place;
};

struct frame_tw {
	struct frame_simple  f1;
	struct frame_complex frame_cmpl;
};

struct frame_th {
	struct frame_tw f2;
	struct frame_complex frame_cmpl;
};

struct frame_fo {
	struct frame_th f3;
	struct frame_complex frame_cmpl;
};

