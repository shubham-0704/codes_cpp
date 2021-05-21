# Maps and Sets
```cpp
// Pairs
void explainPair() {
	pair<int, int> p = {1, 3};
	// prints 1 3
	cout << p.first << " " << p.second;
	pair<int, pair<int, int>> p = {1, {3, 4}};
	// prints 1 4 3
	cout << p.first << " " << p.second.second << " " << p.second.first;
	pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1}};
	// Prints 5
	cout << arr[1].second;

}
```

# Set
```cpp
void explainSet() {

    // o(logn)
	set<int>st;
	st.insert(1); // {1}
	st.emplace(2); // {1, 2}
	st.insert(2); // {1, 2}
	st.insert(4); // {1, 2, 4}
	st.insert(3); // {1, 2, 3, 4}

	for(auto &it :alo){
            cout<<it;
        }

	// Functionality of insert in vector
	// can be used also, that only increases
	// efficiency

	// begin(), end(), rbegin(), rend(), size(),
	// empty() and swap() are same as those of above

	// {1, 2, 3, 4, 5}
	auto it = st.find(3);

	// {1, 2, 3, 4, 5}
	auto it = st.find(6);
	if(alo.find(2)==alo.end())cout<<"nahi hai";
	// {1, 4, 5}
	st.erase(5); // erases 5 // takes logarithmic time


	int cnt = st.count(1); 


	auto it = st.find(3);
	st.erase(it); // it takes constant time

	// {1, 2, 3, 4, 5}
	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

	// lower_bound() and upper_bound() function works in the same way
	// as in vector it does.

	// This is the syntax
	auto it = st.lower_bound(2); 

	auto it = st.upper_bound(3); 
}

void explainMultiSet() {
	// Everything is same as set
	// only stores duplicate elements also


	multiset<int>ms;
	ms.insert(1); // {1}
	ms.insert(1); // {1, 1}
	ms.insert(1); // {1, 1, 1}

	ms.erase(1); // all 1's erased

	int cnt = ms.count(1); 

	// only a single one erased
	ms.erase(ms.find(1));


	ms.erase(ms.find(1), ms.find(1)+2);

	// rest all function same as set
}

void explainUSet() { 

    // o(1)  search delete insert worst case o(n)
	unordered_set<int> st;
    // st.insert(),size(),st.find(),st.end()-->pointer when no element is found
    // st.count(),st.erase(s.begin(),s.end())
    // st.clear();


	// lower_bound and upper_bound function
	// does not works, rest all functions are same
	// as above,  it does not stores in any
	// particular order it has a better complexity
	// than set in most cases, except some when collision happens
}
```
<br>

# Map
```cpp

void explainMap() {

	// {key, value}
	map<int, int> mpp;

	map<int, pair<int, int>> mpp;

	map< pair<int, int>, int> mpp;
//insert({keyvalue, mapvalue}) – Adds a new element to the map.
// erase(iterator position) – Removes the element at the position pointed by the iterator or range (mp.begin(),mp.end())
// erase(const g)– Removes the key value ‘g’ from the map.
// clear() – Removes all the elements from the map.

	// key values can be anything
	m.insert({1,2});
    m.insert(make_pair(3,4));
    cout<<m[3];
    m[3]=100; 
	mpp[1] = 2;
	mpp.emplace({3, 1});

	mpp.insert({2, 4});

	mpp[{2,3}] = 10; 

	{
		{1, 2}
		{2, 4}
		{3, 1}
	}

	for(auto it : mpp) {
		cout << it.first << " " << it.second << endl; 
	}
    // if it is iterator u can also use it->first it->second

	// same options for using iterators
	// as we did in vector for the insert function


	cout << mpp[1]; // prints 2
	cout << mpp[5]; // prints 0, since it does not exists


	auto it = mpp.find(3); // points to the position where 3 is found
    if(m.find("ide")!=m.end()) // not found 


	cout << *(it).second; 

	auto it = mpp.find(5); // points to the end of the map since 5 not there

	// lower_bound and upper_bound works exactly in the 
	// same way as explained in the other video 
    
    // This is the syntax
	auto it = mpp.lower_bound(2); 

	auto it = mpp.upper_bound(3); 

	// erase, swap, size, empty, are same as above 

}
{1,2}
{1,3}

void explainMultimap() {
	// everything same as map, only it can store multiple keys
	// only mpp[key] cannot be used here 
	
}


void explainUnorderedMap() {
	// same as set and unordered_Set difference. 
}
```