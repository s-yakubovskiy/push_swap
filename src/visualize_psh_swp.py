import tkinter as tk
width = 800
height = 1200
fps = 1
scale_mod = 1.35

class App(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self.title("Visualisation of PUSH-SWAP project")

        self.c = tk.Canvas(self, width=width, height=height, bg="black")
        self.c.pack()


        f = open("parse.txt", "r")
        f2 = f.readlines()
        # f1 = f.readlines()
        self.f_index = 0
        self.gnl_index = 0
        self.f_data = []
        self.f_data_b = []
        list_merge = []
        list_merge2 = []
        list_tmp3 = []

        for j in f2:
            j = j.split(' | ')
            x = j[0].split(' ')
            x = [int(i) for i in x]
            for i in x:
                list_tmp3.append(i)
        max_num = max(list_tmp3)
        # print("ww{}".format(max_num))
        self.width_scale = height//max_num//2

        f.close()
        f = open("parse.txt", "r")
        f1 = f.readlines()
        for q in f1:
            list_tmp = []
            listA = []
            q = q.split(' | ')
            x = q[0].split(' ')
            # print(x)
            x = [int(i) for i in x]
            for i in x:
                list_tmp.append(i)
            length = len(list_tmp)
            j = 0
            mxlen = max(list_tmp)
            m = max_num
            e = height//max_num
            lj = e
            # print("max num: {}".format(max_num))
            for i in list_tmp:
                if i == 0:
                    i = 1
                elif i < 0:
                    i *= -1
                # listA.append([0, (height // length) * j + 10, ((width // 2) // mxlen) * i - 10, height // length * j + 10])
                # print("i {}".format(i))
                # print("list {}".format(list_tmp))
                listA.append([0, lj, ((width // 2) // max_num) * i - 10, lj])
                lj = lj + e
                j += 1
            list_merge.append(listA)

        for q in f1:
            list_tmp = []
            listB = []
            q = q.split(' | ')
            x = q[1].split(' ')
            if x[0] == '':
                x[0] = -1
            if x[0] == '\n':
                x[0] = -1
            x = [int(i) for i in x]
            for i in x:
                list_tmp.append(i)
            length = len(list_tmp)
            j = 0
            mxlen2 = max(list_tmp)
            m = max_num
            e = height//max_num
            lj = e

            for i in list_tmp:
                if i == 0:
                    i = 1
                # elif i < 0:
                #     i *= -1
                listB.append(
                    [0 + width // 2, lj, ((width // 2) // max_num) * i + width // 2, lj])
                j += 1
                m = m + max_num + 10
                lj = lj + e
            list_merge2.append(listB)
        # print("width scale{}".format(self.width_scale))




        self.f_data.append(list_merge)
        self.f_data_b.append(list_merge2)

        self.f_index = 0  # index so we know which frame to draw next

    def next_frame(self):
        # data = self.f_data[self.f_index]  # fetch frame data
        data = self.f_data[self.f_index]  # fetch frame data
        data2 = self.f_data_b[self.f_index]

        # print(len(data))
        self.c.delete('all')  # clear canvas

        # width_scale = min(height//len(data[self.gnl_index]) - 5, height // len(data2[self.gnl_index]) - 5)
        # print("width scale{}".format(width_scale))
        # print("width scale self{}".format(self.width_scale))
        for i in data[self.gnl_index]:
            # print("i {}".format(i))
            # print(len(data[self.gnl_index]))
            self.c.create_line(i, width=self.width_scale + scale_mod, fill="cyan")

        for i in data2[self.gnl_index]:
            # print("i {}".format(i))
            # print(len(data2[self.gnl_index]))
            self.c.create_line(i, width=self.width_scale + scale_mod, fill="orange")

        # print(len(self.f_data))
        # self.f_index = 0
        # self.c.create_line(data, width=60)  # draw new frame data
        self.f_index += 1  # increment frame index
        self.gnl_index += 1  # increment frame index
        if (self.f_index >= len(self.f_data)):  # check and wrap if at end of sequence
            self.f_index = 0
        self.c.after(fps, self.next_frame)  # call again after 50ms
        # print(self.gnl_index)
        # print(len(self.f_data[0]))
        if self.gnl_index == len(self.f_data[0]):
            self.gnl_index = len(self.f_data[0]) - 1
            self.c.after(20000, self.next_frame)
        # print(self.f_data)


if __name__ == "__main__":
    n_data = [[0, 10, 1, 0], [1, 12, 14, 9]]
    app = App()
    app.next_frame()
    app.mainloop()
