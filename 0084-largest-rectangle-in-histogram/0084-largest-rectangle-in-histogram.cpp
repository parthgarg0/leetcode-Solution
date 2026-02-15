class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // calculate left smaller
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                left[i] = 0;
            else
                left[i] = st.top() + 1;

            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // calculate right smaller
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                right[i] = n - 1;
            else
                right[i] = st.top() - 1;

            st.push(i);
        }

        // calculate area
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            int width = right[i] - left[i] + 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
