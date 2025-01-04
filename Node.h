#include <ostream>

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;

		Node(T data,Node<T>* next=nullptr){this->data=data;this->next=next;}
		friend std::ostream& operator<<(std::ostream& out ,Node<T> &node){
			out << node.data;
			return out;
		}

};
