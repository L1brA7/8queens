#include <iostream>
#include <tuple>

using namespace std;

void ss();
void tab();
void line();

bool** bool_mem_alloc(int N, int M);
tuple<int, int> NM();
void SpotFI(bool **FIELD, int **queens, int s_line, int N, int M);

int main() {

	int N, M;
	tie(N, M) = NM();
	bool** FIELD = bool_mem_alloc(N, M);
	int **queens = (int **)malloc(0 * sizeof(int));
	//queens[0] = (int *)malloc(2 * sizeof(int));
	SpotFI(FIELD, queens, 0, N, M);
	return 0;
}

void ss() {
	printf("\n");
}

void tab() {
	printf("\t");
}

void line() {
	printf("-------------------------------------------------------------------------------------------------\n\n");
}

bool** bool_mem_alloc(int N, int M) {
	bool** ARR = new bool*[N];
	for (int i = 0; i < N; i++)
		ARR[i] = new bool[M];
	return ARR;
}

tuple<int, int> NM() {
	int N, M;
	printf("\n\tEnter N - ");
	cin >> N;
	printf("\n\tEnter M - ");
	cin >> M;
	ss();
	return make_tuple(N, M);
}

void SpotFI(bool **FIELD, int **queens, int s_line, int N, int M) {
	if (s_line == N) return;
	queens = (int **)realloc(queens, (s_line + 1) * sizeof(int));
	queens[s_line] = (int *)malloc(2 * sizeof(int));

	for (int j = 0; j < M; j++) {
		if () {
			FIELD[s_line][j] = true;
			queens[s_line][] =
		}
		SpotFI(FIELD, queens, s_line + 1, N, M);
		FIELD[s_line][j] = false;
	}
}