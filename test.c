#include <stdio.h>
#include "fswrap.h"

int expect_eq_int(int l, int r) {
    return (l == r);
}

void param_test() {
    FsWrap fswp = {0};
    int ret = 0;
    ret = expect_eq_int(FSW_PARAM_ERROR, fswrap_open_sync(NULL, "w", &fswp));
    if (!ret) printf("error %d %d\n",ret, __LINE__);

    ret = expect_eq_int(FSW_PARAM_ERROR, fswrap_open_sync("./test.txt", "w", NULL));
    if (!ret) printf("error %d %d\n",ret, __LINE__);

    ret = expect_eq_int(FSW_PARAM_ERROR, fswrap_open_sync("./test.txt", NULL, &fswp));
    if (!ret) printf("error %d %d\n",ret, __LINE__);    

    ret = expect_eq_int(0, fswrap_open_sync("./test.txt", "w", &fswp));
    if (!ret) printf("error %d %d\n",ret, __LINE__);
}

int main() {
    printf("[test begin]\n");
    param_test();
    printf("[test end]\n");
    return 0;
}