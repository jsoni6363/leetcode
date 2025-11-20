class StockSpanner {
    // Stack will store pairs: (price, span)
    // price = stock price on that day
    // span = number of consecutive previous days with price <= today's price
    stack<pair<int, int>> stack;

public:
    StockSpanner() {}

    int next(int price) {

        int span = 1;  // Every day's span is at least 1 (the day itself)

        // While stack is NOT empty AND the previous price is <= today's price:
        // It means today's price can "absorb" the previous day's span.
        // So we add that span and pop that price.
        while (!stack.empty() && stack.top().first <= price) {

            // Add the previous span to today's span
            span += stack.top().second;

            // Remove that previous (price, span) because
            // it's now merged into today's span
            stack.pop();
        }

        // Push today's price and total span into stack
        stack.push({price, span});

        // Return the computed span
        return span;
    }
};
