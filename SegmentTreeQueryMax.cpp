#include<iostream>

using namespace std;

//Get the middle index of given range
int getMid(int s, int e){
    return s + (e-s)/2;
}

//A recursive function to get the max of values in given range of array

/*
st      -> Pointer to segment tree
node    -> Index of current node in the segment tree
ss & se -> Starting and ending indexes of the segment represented by current node
l & r   -> Starting and ending indexes of range query
*/
int maxUtil(int* st, int ss, int se, int l, int r, int node){
    
    // If segment of this node is completely
    // part of given range then return the max of segment
    if (l <= ss && r >= se){
        return st[node];
    }

    // This segment of this node does not belong to given range
    if (se < l || ss > r){
        return -1;
    }

    int mid = getMid(ss, se);

    return max(maxUtil(st, ss, mid, l, r, 2*node + 1), 
            maxUtil(st, mid + 1, se, l , r, 2*node + 2));
}

/* A recursive function to update the nodes which have the given index in their range*/
void updatedValue(int arr[], int* st, int ss, int se, int index, int value, int node){
    if (index < ss || index > se){
        cout << "Invalid Input" << endl;
        return;
    }

    if (ss == se){
        arr[index] = value;
        st[node] = value;
    } else {
        int mid = getMid(ss, se);

        if (index >= ss && index << mid){
            updatedValue(arr, st, ss, mid, index, value, 2*node+1);
        } else {
            updatedValue(arr, st, mid + 1, se, index, value, 2*node+2);
        }

        st[node] = max(st[2*node + 1], st[2*node+2]);
    }
    return;
}

//Return max of elements in range from
int getMax(int* st, int n, int l, int r){
    if (l < 0 || r > n-1 || l>r){
        cout << "Invalid input" << endl;
        return;
    }

    return maxUtil(st, 0, n-1, l, r, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se]
// si is index of current node in segment tree st
int contructSTUtil(int arr[], int ss, int se, int* st, int si){
    if (ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and right subtrees
    // And store the max of value in the node
    int mid = getMid(ss, se);

    st[si] = max(contructSTUtil(arr, ss, mid, st, si*2+1),
            contructSTUtil(arr, mid+1, se, st, si*2+2));

    return st[si];
}


int main(){

}