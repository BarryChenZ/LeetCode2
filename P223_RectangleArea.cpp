public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //先確認有沒有相交 
        if(intersect(A, B, C, D, E, F, G, H)){
            return (C-A) * (D-B) - (min(C,G) - max(A,E)) * (min(D,H) - max(B,F)) + (G-E) * (H-F);;
        }
        return (C-A) * (D-B) + (G-E) * (H-F);
    }
    bool intersect(int A, int B, int C, int D, int E, int F, int G, int H){
        //ABCD,EFGH
        if(max(A, E) > min(C, G) || max(B, F) > min(D, H)) return false;
        return true;
    }
};
