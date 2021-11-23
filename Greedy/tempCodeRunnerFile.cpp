 for (int i = 1; i < n; i++)
    {
        if (v[i][0] > end)
        {
            end = v[i][1];
            count++;
        }
    }