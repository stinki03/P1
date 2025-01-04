#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "List.h"


template<typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
	public:
		ListArray(): max(MINSIZE), n(0){
			arr = new T[max];
		}
		
		~ListArray(){
			delete[] arr;
		}
		
		T operator[](int pos){
			if (pos >= 0 || pos < n ){
				return arr[pos];
			}else{
				throw std::out_of_range("Posición inválida!");
			}
		}
		
		friend std::ostream& operator<<(std::ostream &out, ListArray<T>& list){
			out << "list => [" ;
			for (int i=0 ;i < list.n;i++){
				out << list.arr[i];
				if (i < list.n-1){ out << " , "; }
			}
			out << "]";
			return out;
		}
		
		void insert(int pos, T e) override{
			if (pos<0 || pos > n){throw std::out_of_range("Posición inválida!");}
			if (n>=max){resize(max*2);}
			for (int i=n;i>pos;i--){arr[i]=arr[i-1];}
			arr[pos]=e;
			++n;		
		}
		
		void append(T e) override {
			insert(n,e);
		}

		
		void prepend(T e) override {
			insert(0,e);
		}
		
		T remove(int pos) override {
			if(pos < 0 || pos > n-1){
				throw std::out_of_range("Posición inválida!");
			}
			T elem = arr[pos];
			for (int i=pos;i<n;i++){
				arr[i]=arr[i++];
			}
			--n;
			if (n > 0 && ( n <= max / 4)){
				resize(max / 2);
			}
			return elem;
		}
		
		T get(int pos) override {
			if(pos < 0 || pos > n-1){
				throw std::out_of_range("Posición inválida!");
			}
			return arr[pos];
		}
		
		int search(T e) override { 
			for (int i=0;i<max;i++){
				if (arr[i] == e){return i;}
			}	
			return -1;
		}
		
		bool empty() override {
			return n==0;
		}
		
		int size() override {return n;}
		
	private:	
		void resize(int new_size) {
			T* new_arr = new T[new_size];
			for (int i=0;i<n;++i){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}
};


#endif
