// Custom compare function for sorting pairs
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    // Primary sort by the first element (ascending)
    if (a.first != b.first) 
        return a.first < b.first; 
    
    // Secondary sort by the second element (descending)
    return a.second > b.second; 
}
