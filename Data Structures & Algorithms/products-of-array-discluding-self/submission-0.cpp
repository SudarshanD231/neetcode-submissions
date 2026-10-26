int* productExceptSelf(int* nums, int n) {
    int* final = calloc(n, sizeof(int));
    int product = 1;
    int zerocount = 0;
    int prodexceptzero = 1;

    for (int i = 0; i < n; i++) {
        product *= nums[i];

        if (nums[i] == 0) {
            zerocount++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            continue;
        }

        prodexceptzero *= nums[i];
    }

    if (zerocount > 1) {
        return final;
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            final[i] = prodexceptzero;
        } else if (zerocount == 1) {
            final[i] = 0;
        } else {
            final[i] = product / nums[i];
        }
    }

    return final;
}