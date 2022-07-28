#include"Header.h"
rabota::rabota(const unsigned size) {
	this->table.reserve(size);
	this->buffer.reserve(size);
	this->buffer1.reserve(size);
	//this->buffer = vector<int>(size, 0);
	this->used.reserve(size);
	for (int i = 0; i < size; i++) {
		this->buffer.push_back(0);
		this->buffer1.push_back(0);
		this->used.push_back(0);
	}
	for (int i = 0; i < size; i++) {
		this->table.push_back(buffer);
	}
	this->prise = 0;
	this->r = 0;
	this->size = size;
}
ifstream& operator>>(ifstream& f, rabota& r) {
	if (f.is_open()) {
		for (int i = 0; i < r.size; i++) {
			for (int j = 0; j < r.size; j++) {
				if (f.eof() || f.fail()) return f;
				f >> r.table[i][j];
			}
		}
	}
	return f;
}
ofstream& operator<<(ofstream& f, rabota& r) {
	if (r.result.size() != 0) f << "prise " << r.result[0][r.size] << endl;
	for (int i = 0; i < r.result.size(); i++) {
		for (int j = 0; j < r.size; j++) {
			f << r.result[i][j] + 1 << " ";
		}
		f << endl;
	} 
	return f;
}
void rabota::foo() {
	if (!this->result.empty() && this->r == 0) {
		this->result.clear();
		this->prise = 0;
		for (int i = 0; i < this->size; i++) {
			this->used[i] = 0;
		}
	}
	if (this->r == this->size) {
		if (this->result.size() == 0) {
			this->result.push_back(this->buffer);
			this->result[0].push_back(this->prise);
		}
		else if (this->result[0][this->r] == this->prise) this->result.push_back(this->buffer);
		else if (this->result[0][this->r] > this->prise) {
			this->result.clear();
			this->result.push_back(this->buffer);
			this->result[0].push_back(this->prise);
		}
	}
	else {
		for (int i = 0; i < this->size; i++) {
			if (!this->used[i]) {
				this->used[i] = 1;
				this->prise += this->table[i][this->r];
				this->buffer[this->r] = i;
				this->r++;
				foo();
				this->r--;
				this->used[i] = 0;
				if (this->table[i][this->r] >= 0)this->prise -= this->table[i][this->r];
				else this->prise += -this->table[i][this->r];
			}
		}
	}
}
void rabota:: foo1() {
	if (!this->result.empty()) this->result.clear();
	int a = INT_MAX;// 
	int k = 0;
	for (int j = 0; j < this->size; j++) {
		a = INT_MAX;
		for (int i = 0; i < this->size; i++) {
			if (this->table[i][j] < a && this->used[i] == 0) {
				k = i;
				a = this->table[i][j];
			}
		}
		this->used[k] = 1;
		this->prise += a;
		this->buffer[j] = k;
	}
	this->result.push_back(this->buffer);
	this->result[0].push_back(this->prise);
	this->prise = 0;
}
bool rabota::dfs(vector<vector<int>>& g, int v) {
	if (used[v])  return false;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (this->buffer[to] == -1 || dfs(g,this->buffer[to])) {
			this->buffer[to] = v;
			this->buffer1[v] = to;
			return true;
		}
	}
	return false;
}
void rabota::Serb() {

	vector<vector<int>> g(this->size);
	int min1 = INT_MAX;
	vector<int> min(this->size);
	int count = 0;
	vector<vector<int>> a = this->table;
	for (int y = 0; 1 ;y++) {
		min.assign(this->size, INT_MAX);
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++)
				cout << " " << a[i][j];
			cout << endl;

		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (a[i][j] < min[i]) min[i] = a[i][j];
			}
		}
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				a[i][j] -= min[i];
			}
		}
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++)
				cout << " " << a[i][j];
			cout << endl;

		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	
		min.assign(this->size, INT_MAX);
	
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (a[j][i] < min[i]) min[i] = a[j][i];
			}
		}
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				a[j][i] -= min[i];
			}
		}
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++)
				cout << " " << a[i][j];
			cout << endl;

		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i < this->size; i++) {
			g[i].clear();
		}
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (a[i][j] == 0) g[i].push_back(j);
			}
		}
		
		
		this->buffer.assign(this->size, -1);
		this->buffer1.assign(this->size, -1);
		this->used.assign(this->size, 0);
		//for (int i = 0; i < this->size ; i++) {
			//for (int j = 0; j < g[i].size(); j++)
				//cout << " " << g[i][j];
			//cout << endl;

		//}
		for (int i = 0; i < this->size; ++i) {
			dfs(g, i);
			this->used.assign(this->size, 0);
		}
		for (int i = 0; i < this->size; i++) {
			if (this->buffer[i] == -1) {
				continue;
			}
			a[this->buffer[i]][i] = -1;
			count++;

		}
		if (count == this->size) break;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else {
			
			for (int i = 0; i < this->size; i++) {
				g[i].clear();
			}
			for (int i = 0; i < this->size; i++) {
				for (int j = 0; j < this->size; j++) {
					if (a[i][j] == 0) g[i].push_back(j);
				}
			}
			int s = 0;
			vector<int> k;
			vector<int> kk(this->size);
			this->used.assign(this->size, 0);
			this->buffer.assign(this->size, -1);
			this->buffer1.assign(this->size, -1);
			for (int i = 0; i < this->size;i++) {
				for(int j = 0; j < this->size; j++){
					if (a[i][j] == -1) kk[i] = -1;
				}
			}
			//return;
			
			vector<int> lll;
			for (int i = 0; i < this->size; i++) {
				if (kk[i] == 0) {
					venger(a,g,k,lll,i);
					this->buffer.assign(this->size, -1);
					//this->used.assign(this->size, 0);
				}
			}
			this->buffer.assign(this->size, 0);
			this->buffer1.assign(this->size, 0);
			for (auto i = k.begin(); i != k.end(); i++) {
				this->buffer[*i] = 1;
			}
	
			for (auto i = lll.begin(); i != lll.end(); i++) {
				this->buffer1[*i] = 1;
			}
			
			min1 = INT_MAX;
			for (int i = 0; i < this->size; i++) {
				for (int j = 0; j < this->size; j++) {
					if (a[i][j] < min1 && this->buffer[i] == 1 && this->buffer1[j] == 0) min1 = a[i][j];
				}
			}
			for (int i = 0;i<this->size;i++) {
				for (int j = 0; j < this->size; j++) {
					if (a[i][j] == -1) a[i][j] = 0;
				}
			}
			
			for (int i = 0; i < this->size; i++) {
				for (int j = 0; j < this->size; j++) {
					if (this->buffer1[j] == 0 && this->buffer[i] == 1)  a[i][j] -= min1;
					if(this->buffer1[j] == 1 && this->buffer[i] == 0) a[i][j] += min1;
				}
			}
			this->used.assign(this->size, 0);
			this->buffer.assign(this->size, -1);
			this->buffer1.assign(this->size, -1);
			for (int i = 0; i < this->size ; i++) {
			for (int j = 0; j < this->size; j++)
				cout << " " << a[i][j];
			     cout << endl;

		}
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			count = 0;
			
		}
		
	
	}
	this->prise = 0;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (a[i][j] == -1) { 
				this->buffer[i] = j;
				this->prise += this->table[i][j];
				
			}
		}
	}
	this->result.push_back(this->buffer);
	this->result[0].push_back(this->prise);
}
void rabota::venger(vector<vector<int>>& a,vector<vector<int>> &g, vector<int>& k,vector<int>&v, int i) {
	while (dfs(g,i)) {
		int u =- 1;
		k.push_back(i);
		for (int j = 0; j < this->size; j++) {
			if (a[j][this->buffer1[i]] == -1) {
				u = j;
				v.push_back(this->buffer1[i]);
				k.push_back(u);
			}
		}
		if (u == -1) {
			this->buffer[this->buffer1[i]] = -1;
			this->buffer1[i] = -1;
			v.push_back(this->buffer1[i]);
			return;
		}
		venger(a,g,k,v,u);
		k.push_back(u);
		this->used.assign(this->size, 0);
	}
	this->used.assign(this->size, 0);
}