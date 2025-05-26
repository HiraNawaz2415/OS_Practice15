# paging_simulator.py

def paging_simulator():
    print("=== Logical to Physical Address Converter ===\n")

    page_size = int(input("Enter page size (in bytes): "))
    num_pages = int(input("Enter number of pages: "))

    # Create page table
    page_table = {}
    print("\nEnter frame number for each page:")
    for i in range(num_pages):
        frame = int(input(f"Page {i} → Frame: "))
        page_table[i] = frame

    logical_address = int(input("\nEnter logical address: "))
    
    # Calculate page number and offset
    page_number = logical_address // page_size
    offset = logical_address % page_size

    # Check if page exists in page table
    if page_number in page_table:
        frame_number = page_table[page_number]
        physical_address = frame_number * page_size + offset

        print(f"\nPage Number: {page_number}")
        print(f"Offset: {offset}")
        print(f"Frame Number from Page Table: {frame_number}")
        print(f"Physical Address: {physical_address}")
    else:
        print("Invalid page number! Page not found in page table.")


if __name__ == "__main__":
    paging_simulator()
