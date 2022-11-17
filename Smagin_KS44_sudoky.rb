MAX_ROW = 9          
MAX_COL = 9       

def sdk(matrix, row, column)

    if (row == MAX_ROW-1 && column == MAX_COL)
        return true
    end

    if column == MAX_COL 
        column = 0
        row += 1
    end

    if (matrix[row][column] != 0)
        return sdk(matrix, row, column + 1)
    end

    for var in 1..9 do
        condition_admit = true
        for i in 0..MAX_COL - 1 do 
            if matrix[row][i] == var
                condition_admit = false
                break
            end
        end
    
        for i in 0..MAX_ROW - 1 do
            if matrix[i][column] == var
                condition_admit = false
                break
            end
        end
    
        bust_r = row - row % 3
        bust_c = column - column % 3
        for i in 0..2 do
            for j in 0..2 do
                if (matrix[i + bust_r][j + bust_c] == var)
                    condition_admit = false
                    break
                else 
                    next
                end
            end
            break
        end

        if (condition_admit)
            matrix[row][column] = var

            if (sdk(matrix, row, column + 1))
                return true
            end
        end

        matrix[row][column] = 0
    end
    
    false
end

def print_matrix(matrix)
    for i in 0..MAX_ROW - 1 do
        for j in 0..MAX_COL - 1 do
            print "#{matrix[i][j]} "
        end
        puts 
    end
end

grid = [[ 3, 0, 6, 5, 0, 8, 4, 0, 0 ],
        [ 5, 2, 0, 0, 0, 0, 0, 0, 0 ],
        [ 0, 8, 7, 0, 0, 0, 0, 3, 1 ],
        [ 0, 0, 3, 0, 1, 0, 0, 8, 0 ],
        [ 9, 0, 0, 8, 6, 3, 0, 0, 5 ],
        [ 0, 5, 0, 0, 9, 0, 6, 0, 0 ],
        [ 1, 3, 0, 0, 0, 0, 2, 5, 0 ],
        [ 0, 0, 0, 0, 0, 0, 0, 7, 4 ],
        [ 0, 0, 5, 2, 0, 6, 3, 0, 0 ] ]


puts ":: Input grid"
print_matrix(grid)

puts ":: Output grid"
sdk(grid, 0, 0)
print_matrix(grid)