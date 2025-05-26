import tkinter as tk
from tkinter import messagebox

class PagingSimulatorGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Paging Simulator - Logical to Physical Address")
        self.root.geometry("400x500")
        self.page_table = {}

        self.setup_widgets()

    def setup_widgets(self):
        tk.Label(self.root, text="Enter Page Size (in bytes):").pack()
        self.page_size_entry = tk.Entry(self.root)
        self.page_size_entry.pack()

        tk.Label(self.root, text="Enter Number of Pages:").pack()
        self.num_pages_entry = tk.Entry(self.root)
        self.num_pages_entry.pack()

        tk.Button(self.root, text="Create Page Table", command=self.create_page_table_inputs).pack(pady=10)

        self.page_table_frame = tk.Frame(self.root)
        self.page_table_frame.pack()

        self.address_frame = tk.Frame(self.root)
        self.address_frame.pack(pady=10)

    def create_page_table_inputs(self):
        self.page_table.clear()
        for widget in self.page_table_frame.winfo_children():
            widget.destroy()
        for widget in self.address_frame.winfo_children():
            widget.destroy()

        try:
            self.page_size = int(self.page_size_entry.get())
            self.num_pages = int(self.num_pages_entry.get())
        except ValueError:
            messagebox.showerror("Error", "Invalid input! Enter integers.")
            return

        self.frame_entries = []
        tk.Label(self.page_table_frame, text="Enter Frame Numbers:").pack()
        for i in range(self.num_pages):
            frame_row = tk.Frame(self.page_table_frame)
            frame_row.pack()
            tk.Label(frame_row, text=f"Page {i} → Frame: ").pack(side=tk.LEFT)
            frame_entry = tk.Entry(frame_row, width=5)
            frame_entry.pack(side=tk.LEFT)
            self.frame_entries.append(frame_entry)

        tk.Label(self.address_frame, text="Enter Logical Address:").pack()
        self.logical_address_entry = tk.Entry(self.address_frame)
        self.logical_address_entry.pack()

        tk.Button(self.address_frame, text="Convert to Physical Address", command=self.convert_address).pack(pady=10)
        self.result_label = tk.Label(self.address_frame, text="")
        self.result_label.pack()

    def convert_address(self):
        try:
            for i in range(self.num_pages):
                self.page_table[i] = int(self.frame_entries[i].get())

            logical_address = int(self.logical_address_entry.get())
            page_number = logical_address // self.page_size
            offset = logical_address % self.page_size

            if page_number in self.page_table:
                frame_number = self.page_table[page_number]
                physical_address = frame_number * self.page_size + offset
                self.result_label.config(
                    text=f"Page: {page_number}, Offset: {offset}\n"
                         f"Frame: {frame_number}\nPhysical Address: {physical_address}"
                )
            else:
                self.result_label.config(text="Invalid page number (not in page table)")

        except ValueError:
            messagebox.showerror("Error", "Enter valid integer values for frames and address.")

if __name__ == "__main__":
    root = tk.Tk()
    app = PagingSimulatorGUI(root)
    root.mainloop()
