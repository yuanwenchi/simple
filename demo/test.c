#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cp.h"

struct complexor {
	u8  *name;
	u8  type;

	u32 dimen;
	s32 *value;
};

int complexor_set_name(struct complexor *comp, u8 *name)
{
	if (comp == NULL)
		return -ENODEV;

//	comp->name = malloc(strlen(name) + 1);
	comp->name = name;
}

int complexor_create(struct complexor *comp, u32 dimen)
{
	int ret = 0;

//	comp = malloc(sizeof(struct complexor));
//	if (comp == NULL) {
//		ret = -ENOMEM;
//		goto FREE_EXIT;
//	}
//	memset(comp, 0, sizeof(struct complexor));

	comp->dimen = dimen;
	comp->value = malloc(comp->dimen);
	if (comp->value == NULL) {
		ret = -ENOMEM;
		goto FREE_EXIT;
	}
	memset(comp->value, 0, comp->dimen);

	return ret;

FREE_EXIT :
	if (comp != NULL && comp->value != NULL)
		free(comp->value);
	if (comp != NULL)
		free(comp);
	printf("%s : fail ret = %d\n", __func__, ret);

	return ret;
}

struct complexor c;

main()
{
	complexor_create(&c, 3);
	printf("1\n");
	complexor_set_name(&c, "yuan");

	printf("name %s\n", c.name);
}
