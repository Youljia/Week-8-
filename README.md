# Week-8-

## C++学习

### Vector

- Vector能在运行的时候快速添加元素且不需要提前开辟空间
- Vector是一个类模板，通过其创建对象称作实例化
- Vector的初始化（五种方式）
- 基本操作
- **下标运算符[]**
  1. 可以通过下标得到已存在元素的引用
  2. 不可用下标访问未知元素
  3. 不用下标添加元素

### 智能指针

​		*智能指针作用*

​				自动释放new的空间

```c++
#include<memory>
	//智能指针
	auto_ptr<A> ptr(new A(10));
	//通过指针访问
	ptr->show();
	//通过对象访问
	(*ptr).show();
```

### 自定义的string类

*库函数*

```c++
#include<string>
	//string其实是一个已经封装好了的类
	string name = "nihaoa";
	//调用了拷贝构造函数（深拷贝）
	string name2 = name;
```

### 任意数

```c++
C++ 生成任意数的函数  rand()
    //使用方法1
    int i= rand()%100;  //生成[0,100)的随机整数
    //使用方法2
    int i = rand()%n+a;  //生成[a,n-a)的随机整数
```

## 数据结构与算法

### 快速排序法

* 特点-->在运行过程中不需要另开内存

* 逻辑-->将元素e放在最终应该在的位置，让e前面的元素小于e，e后面的元素大于e

* 递归函数的“宏观”意义 --> 对[l,r]进行排序

  ```c++
  	//递归排序
  	//意义:对[l,r]进行排序
  	void quick_sort(int l, int r)
  	{
  		if (l >= r)
  			return;
  		int p = partition(l, r);
  		quick_sort(l, p - 1);
  		quick_sort(p + 1, r);
  	}
  ```

  

* 核心代码-->实现逻辑 (  [<e]   [e]   [>e] )

  ```c++
      //将元素e排在它最终应该在的位置
  	//保证（<e）e (>e)
  	int partition(int l, int r)
  	{
  		int i = l;
  		int e = l + 1;
  		for (e; e <= r; ++e)
  		{
  			if (this->arra[e] < this->arra[l])
  			{
  				i++;
  				swap(arra[i], arra[e]);
  			}
  		}
  		swap(arra[i], arra[l]);
  		return i;
  	}
  PS-->当左右两个部分接近均分元素时，性能很高。
      但是如果左右两部分元素分布及其不均匀的时候，性能就会退化！
  ```

* 为排序添加随机性

  Q-->当有序或者近乎有序的情况下，快速排序算法的功能会退化

  A-->由于每次partition的三部分，<e的部分为空，所以时间复杂度退化成了O(n*n)

* 双路排序算法

  ```c++
  int partition(int l, int r)
  	{
  		int i = l + 1;
  		int j = r;
  		while (true)
  		{
  			while (i <= j && arra[i] < arra[l])
  				++i;
  			while (i <= j && arra[j] > arra[l])
  				--j;
  
  			if (i >= j)
  				break;
  
  			swap(arra[i], arra[j]);
  			++i;
  			--j;
  		}
  		swap(arra[j], arra[l]);
  		return j;
  	}
  ```

* 三路快速排序法

  改进相同元素过多的情况

* 复杂度分析

  最差情况-->存在一种情况，使得快排的时间复杂度为O（n^2）

  但是通过改进，此种情况概率极低

  -->快排具有随机性，使用数学期望的方法来推断

  ​       (每一次分区的时候，有可能左边多右边少，也可能右边多左边少，所以总的期望来说每次都是均分)

  ​       -->由此得出   复杂度为O（nlogn）

* 复杂度分析方法总结
  1. 能找到一组数据，使得排序情况最差  -- >  用最差的情况来求得复杂度
  2. 不能找到一组数据，但是存在该种可能且可能性极低 -- > 用数学期望
  3. 分摊复杂度
