type MyHashMap struct {
	storage []int
}

func Constructor() MyHashMap {
	storage := make([]int, 1000001)
	for i := range storage {
		storage[i] = -1
	}

	return MyHashMap{
		storage: storage,
	}
}

func (this *MyHashMap) Put(key int, value int) {
	this.storage[key] = value
}

func (this *MyHashMap) Get(key int) int {
	return this.storage[key]
}

func (this *MyHashMap) Remove(key int) {
	this.storage[key] = -1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */