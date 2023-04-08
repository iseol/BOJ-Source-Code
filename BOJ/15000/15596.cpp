long long sum(std::vector<int> &a) {
    long long sum = 0;
    for (int i : a) sum += i;
    return sum;
}