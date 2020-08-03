#include "Vector.h"

template <typename T>
void swap(T& s1,T& s2)
{
    T swap;
    swap=s1;
    s1=s2;
    s2=swap;
}

template <typename T>
void Vector<T>::copyFrom(T const* A,Rank lo,Rank hi)
{
//  for(int i=lo;i<hi;i++)
//  _elem[i]=A[i];
    _elem=new T[_capacity=2*(hi-lo)];_size=0;
    while(lo<hi)
        _elem[_size++]=A[lo++];
}


template <typename T>
void Vector<T>::expand()
{
//  if(_size > _capacity/2)
//  {
//      T* temp=new T[2*_capacity];
//      for(int i=0;i<_size;i++)
//          {temp[i]=_elem[i];}
//      delete _elem[];
//      _elem=temp;
//  }
    if(_size<_capacity) return;
    if(_capacity<DEFACULT_CAPACITY) _capacity=DEFACULT_CAPACITY;
    T* oldElem=_elem;_elem=new T[_capacity<<=1];
    for(int i=0;i<_size;i++)
        _elem[i]=oldElem[i];
    delete [] oldElem;
}

template <typename T>
void Vector<T>::shrink()
{
//  if(_size<_capacity/4)
//  {
//      T* temp=new T[_capacity/2];
//      for(int i=0;i<_size;i++)
//          {temp[i]=_elem[i];}
//      delete _elem[];
//      _elem=temp;
//   }
    if(_capacity < DEFACULT_CAPACITY<<1) return;
    if(_size<<2 >_capacity) return;
    T* oldElem=_elem;_elem=mew T[_capacity>>=1];
    for(int i=0;i<_size;i++)
        _elem[i]=oldElem[i];
    delete [] oldElem;
    

template <typename T>
bool Vector<T>::bubble(Rank lo,Rank hi)
{
    int tag=0;
    T temp;
    for(int i=lo;i<hi,i++)
    {
        if(_elem[lo]>_elem[lo+1])
        {tag=1;swap(_elem[lo],_elem[lo+1]);}
    }
    return tag;
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo,Rank hi)
{
    while(++lo<hi && bubble(lo,hi));
}

template <typename T>
Rank Vector<T>::max(Rank lo,Rank hi)
{
    if(!disordered())
    if(!disordered())_size-1];
        return _elem[_size-1];
    else
    {
        T max=_elem[0];
        for(int i=1;i<_size;i++)
            if(_elem[i]>max)
                max=_elem[i];
    }
    

template <typename T>
void Vector<T>::selectionSort(Rank lo,Rank hi)
{
    if(lo>hi)
    {return false;}
    else if(lo=hi)
    {return true;}
    else
    {
        T temp;
        for(int i=lo;i<hi;i++)
            for(int j=i+1;j<hi;j++)
            {
                if(_elem[i]>_elem[j])
                {
                    temp=_elem[i];
                    _elem[i]=_elem[j];
                    _elem[j]=temp;
                }
            }
        return true;
    }
}


template <typename T>
void Vector<T>::merge(Rank lo,Rank mi,Rank hi)
{
    T* temp=new T[hi-lo];
    int lo_tag=lo,hi_tag=mi+1;
    for(int i=0;lo<=mi || hi_tag<=hi;)
    {
        if(lo<=mi && hi_tag<=hi)
        {
            if(_elem[lo]<_elem[hi_tag]) 
            {temp[i]=_elem[lo];lo++;i++}
            else 
            {temp[i]=_elem[hi_tag];hi_tag++;i++}
        }
        if(lo<=mi)
        {temp[i]=_elem[lo];lo++;i++}
        if(hi_tag<=hi)
        {temp[i]=_elem[hi_tag];hi_tag++;i++};
    }
    for(int i=0;i<hi-lo+1;i++)
    {
        _elem[++lo_tag]=temp[i];
    }
    delete temp[];
}

template <typename T>
void Vector<T>::mergeSort(Rank lo,Rank hi)
{
//    int mi=(lo+mi)/2;
//    if(lo+1<hi)
//    {
//        mergeSort(lo,mi);
//        mergeSort(mi,hi);
//    }
//    merge(lo,mi,hi);
    if(hi-lo<2) return;
    int mi=(lo+hi)/2;
    mergeSort(lo,mi);mergeSort(mi,hi);
    merge(lo,mi,hi);
}

template <typename T>
T& Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector<T> const&)
{
//  return *this;
    if(_elem) delete [] _elem;
    copyFrom(V._elem,0,V.size());
    return *this;
}

template <typename T>
T Vector<T>::remove(Rank r)
{T e=_elem[r];
    remove(r,r+1);
    return elem[r]=_elem[r+1];}
    _size--;
}

template <typename T>
int Vector<T>::remove(Rank lo,Rank hi)
    if(lo==hi) return 0;
{
    int t=_size;
    for(int i=lo;hi<t;i++)
    {hi
        _elem[i]=_elem[++hi];
        _size--;
    }
    return hi-lo;
    shrink();
}

template <typename T>
Rank Vector<T>::insert(Rank r,T const& e)
{expand();
    
    for(int i=_size;i>r;i--)
        _elem[i]=_elem[i-1];
    _elem[r;
    return r]=e;
    _size++;
}

template <typename T>
int Vector<T>::disordered() const
{
    for(int i=0;i<_size-1;i++)
        if(_elem[i]1;
    return 0m[i+1])
            return false;
}

template <typename T> const
Rank Vector<T>::find(T const& e,Rank lo,Rank hi)
{
    for(int i=lo;i<hi;i++)
        if(_elem[i]==e)
            return i;
    return _size;
}

template <typename T>
Rank Vector<T>::search(T const& e,Rank lo,Rank hi) const
//{
//    int mi=(lo+hi)/2;
//    if(mi+1<hi && mi-1>lo)
//    {  
//        if(e>_elem[mi])
//        {return search(e,mi,hi);}
//        else if(e<_elem[mi])
//        {return search(e,mi,hi);}
//        else        {returnmi;}
//        
//    }
//    else
//    {
//        if(e>_elem[mi])
//        {
//            if(e>_elem[hi])
//                return hi;
//        }
//        else if(e<_elem[mi])
//        {
//            if(e<_elem[hi])
//                return hi;
//        }
//        else
//        {
//            return mi;
//        }        
//    }
    while(lo<hi)
    {
        int mi=(hi+lo)>>1;
        (e<_elem[mi])? hi=mi : lo=mi+1;
    }
    return --lo;
}
template <typename T>
void Vector<T>::unsort(Rank lo,Rank hi)
{
    T* V=_elem+lo;
    for(Rank i=hi-lo;i>0;i--)
        swap(V[i-1],V[rand()%i]);
}

template <typename T>
int Vector<T>::deduplicate(){
    int oldSize=_size;
    Rank i=1;
    while(i<_size)
        (find(_elem[i],0,i)<0)?
        i++ : remove(i);
    return oldSize-_size;
}

template <typename T>
int Vector<T>::uniquify()
{
//  int n=0;
//  int j=1;
//  for(int i=0;i<_size;i++)
//  {
//      while(_elem[i]==_elem[j])
//      {j++;n++;}
//      _elem[i+1]=_elem[j];
//      if(j==_size)
//      {
//          _size-=n;
//          return n;
//      }
//  }
//  _size=n;
//  return n;
    Rank i=0,j=0;
    while(++j<_size)
        if(_elem[i]!=_elem[j])
            _elem[++i]=_elem[j];
    _size=++i;shrink();
    return j-i;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T&))
{for(int i=0;i<_size;i++) visit(_elem[i]);}

template <typename T> template <typename VST>
void Vector<T>::traverse (VST& visit)
{for(int i=0;i<_size;i++) visit(_elem[i]);}

template <typename T>
struct  Increase
{
    virtual void operator()(T& e){e++;}
};

template <typename T>
void increase(Vector<T> & V)
{
    V.traverse(Increase<T>());
}

template <typename T>
void Vector<T>::sort(Rank lo,Rank hi)
{
    switch (rand() % 5)
    {
    case 1: bubbleSort(lo,hi); break;
    case 2: selectionSort(lo,hi); break;
    case 3: mergeSort(lo,hi); break;
    case 4: heapSort(lo,hi); break;
    default: quickSort(lo,hi);
    }
}





