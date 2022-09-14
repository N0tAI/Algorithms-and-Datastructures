// Assuming a 2-3 tree (B(+) tree of order 3)
// Minimum number of nodes = n = 2 ^ (height(tree) + 1) - 1
// Maximum number of nodes = n = (3^(h + 1) - 1) / (3 - 1)
// Minimum tree height = h = log3(n(3 - 1) + 1) - 1
// Maximum tree height = h = log2(n - 1) - 1
// Therefore tree height is always logarithmic