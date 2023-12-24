randints=$(python3 randints.py)
output_file="output.txt"

# Run push_swap and redirect its output to a file
./push_swap "$randints" > "$output_file"

# Print the contents of the output file
echo "Push Swap Output:"
cat "$output_file"

# Run checker_linux with the same input
./checker_linux "$randints" < "$output_file"
