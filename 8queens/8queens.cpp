#include <iostream>
#include <tuple>

using namespace std;

void ss();
void tab();
void line();

bool** bool_mem_alloc(int N, int M);
tuple<int, int> NM();
void SpotFI(bool **FIELD, int I, int J, int N, int M);
void cl_line(bool **FIELD, int line, int M);

//true - чисто 
//false - найдена угроза
bool vert_check(bool **FIELD, int I, int J, int N);
bool diag_check(bool **FIELD, int I, int J, int N, int M);

int main() {
	int N, M;
	tie(N, M) = NM();
	bool** FIELD = bool_mem_alloc(N, M);
	FIELD[0][0] = true;
	//cout << diag_check(FIELD, 5, 5, N, M);
	SpotFI(FIELD, 1, 0, N, M);
	ss();
	for (int i = 0; i < N; i++) {
		tab();
		for (int j = 0; j < M; j++) {
			printf("%2i", FIELD[i][j]);
		}
		ss();
	}
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
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ARR[i][j] = false;
		}
	}
	
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

void SpotFI(bool **FIELD, int I, int J, int N, int M) {
	if (I == N) {
		cout << "FOUND" << endl;
		return;
	}
	for (int j = J; j < M; j++) {
		if (vert_check(FIELD, I, j, N)) {
			if (diag_check(FIELD, I, j, N, M)) {
				FIELD[I][j] = true;
				SpotFI(FIELD, I + 1, 0, N, M);
				break;
			}
		}
	}
}

bool vert_check(bool **FIELD, int I, int J, int N) {
	for (int i = 0; i < N; i++) {
		if (FIELD[i][J] == true)
			return false;
	}
	return true;
}

bool diag_check(bool **FIELD, int I, int J, int N, int M) {
	int j = 0;
	//shrinking diags
	if (I >= J) {
		for (int i = I - J; i < N; i++) {
			if (FIELD[i][j] == true && i != I && j != J) return false;
			//FIELD[i][j] = true;
			j++;
		}
	}
	else {
		j = J - I;
		for (int i = 0; i < N; i++) {
			if (FIELD[i][j] == true && i != I && j != J) return false;
			//FIELD[i][j] = true;
			j++;
		}
	}
	
	//growing diags
	if (I + J < N)  {
		j = 0;
		for (int i = I + J; i >= 0; i--) { // 
			if (FIELD[i][j] == true && i != I && j != J) return false;
			//FIELD[i][j] = true;
			j++;
		}
	}
	else {
		j = M;
		for (int i = abs(J - I - 2 * (J - 4)); i < N; i++) {
			if (FIELD[i][j] == true && i != I && j != J) return false;
			//FIELD[i][j] = true;
			j--;
		}
	}
	return true;
}

void cl_line(bool **FIELD, int line, int M) {
	for (int j = 0; j < M; j++) {
		FIELD[line][j] = false;
	}
}