# Dequeue
```cpp
void explainDeque() {

	deque<int>dq;//think it as vector
	dq.push_back(1); // {1}
	dq.emplace_back(2); // {1, 2}
	dq.push_front(4); // {4, 1, 2}
	dq.emplace_front(3); // {3, 4, 1, 2}

	dq.pop_back(); // {3, 4, 1}
	dq.pop_front(); // {4, 1}

	dq.back(); 

	dq.front();

	// rest functions same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap

    	for(auto x: dq)
		cout << x << " ";

    deque<int> dq = {10, 20, 5, 30};
	auto it = dq.begin();
	it = dq.insert(it, 7);
	it = dq.insert(it, 2, 3);
	it = dq.erase(it + 1);

	for(int i = 0; i < dq.size(); i++)
		cout<<dq[i]<<" ";
}
```