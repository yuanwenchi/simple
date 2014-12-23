#include <stdio.h>
#include "cp.h"


int dimen_create(struct dimen *dimen, u32 complexity)
{
	int ret = 0;

	if (dimen == NULL) {
		ret = -ENODEV;
		goto FREE_EXIT;
	}
	memset(dimen, 0, sizeof(struct dimen));

	dimen->dimen = complexity;

	dimen->tai = malloc(dimen->dimen);
	if (dimen->tai == NULL) {
		ret = -ENOMEM;
		goto FREE_EXIT;
	}
	memset(dimen->tai, 0, dimen->dimen);

	dimen->ji = malloc(dimen->dimen);
	if (dimen->ji == NULL) {
		ret = -ENOMEM;
		goto FREE_EXIT;
	}
	memset(dimen->ji, 0, dimen->dimen);

	return ret;

FREE_EXIT :
	if (dimen != NULL && dimen->tai != NULL)
		free(dimen->tai)
	if (dimen != NULL && dimen->ji != NULL)
		free(dimen->ji)
	printf("%s : fail errno = %d\n", ret);

	return ret;
}

void dimen_release(struct dimen *dimen)
{
	if (dimen != NULL && dimen->tai != NULL)
		free(dimen->tai)
	if (dimen != NULL && dimen->ji != NULL)
		free(dimen->ji)
}
