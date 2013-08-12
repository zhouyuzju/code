int findKthElem(int A[], int aBeg, int aEnd, int B[], int bBeg, int bEnd, int k){

    //cout << aBeg << " | " << aEnd << " | " << bBeg << " | " << bEnd << " | " << k << endl;

    if(aBeg > aEnd){
        return B[bBeg + k - 1];
    }
    if(bBeg > bEnd){
        return A[aBeg + k - 1];
    }

    int aMid = (aBeg + aEnd) >> 1;
    int bMid = (bBeg + bEnd) >> 1;
    int len = aMid - aBeg + bMid - bBeg + 2;

    if(len > k){
        if(A[aMid] < B[bMid]){
            return findKthElem(A, aBeg, aEnd, B, bBeg, bMid-1, k);
        }
        else{
            return findKthElem(A, aBeg, aMid-1, B, bBeg, bEnd, k);
        }
    }
    else{
        if(A[aMid] < B[bMid]){
            return findKthElem(A, aMid+1, aEnd, B, bBeg, bEnd, k-(aMid-aBeg+1));
        }
        else{
            return findKthElem(A, aBeg, aEnd, B, bMid+1, bEnd, k-(bMid-bBeg+1));
        }
    }
}

