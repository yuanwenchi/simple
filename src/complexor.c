#include <stdio.h>

int complexor_set_name(struct complexor *comp, u8 *name)
{
	if (comp == NULL)
		return -ENODEV;

	comp->name = malloc(strlen(name) + 1);
	strcpy(comp->name, name);

	return 0;
}

int complexor_create(struct complexor *comp, u32 dimen)
{
	int ret = 0;

	if (comp == NULL) {
		ret = -ENODEV;
		goto FREE_EXIT;
	}
	memset(comp, 0, sizeof(struct complexor));

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
	printf("%s : fail errno = %d\n", ret);

	return ret;
}

void complexor_release(struct complexor *comp)
{
	if (comp != NULL && comp->value != NULL)
		free(comp->value);
}
