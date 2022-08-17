void tower_of_hanoi_solution(int n, int tower_a, int tower_b, int tower_c) {
	if (n > 0) {
		tower_of_hanoi_solution(n - 1, tower_a, tower_c, tower_b);
		// transfer a to c
		tower_of_hanoi_solution(n - 1, tower_b, tower_a, tower_c);
	}
}