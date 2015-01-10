#ifndef _INCLUDE_SEIBE_LIST_H_
#define _INCLUDE_SEIBE_LIST_H_

typedef struct seibelist * SeibeList;

SeibeList SeibeList_create(void);
void SeibeList_destroy(SeibeList list);

void SeibeList_push(SeibeList list, void *data);
void SeibeList_unshift(SeibeList list, void *data);
void SeibeList_insert(SeibeList list, int index, void *data);
void *SeibeList_pop(SeibeList list);
void *SeibeList_shift(SeibeList list);
void *SeibeList_remove(SeibeList list, int index);
void *SeibeList_get(SeibeList list, int index);

#endif
