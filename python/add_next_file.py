import os

if __name__ == '__main__':
    c_lecture_order = [
        5, 6, 19, 21, 7, 8, 9, 10, 12, 14, 16, 17, 18, 20, 23, 24, 25, 26, 27, 28,
        30, 31, 29, 32, 33, 43, 55, 60, 71, 83, 87, 88, 89, 98, 100, 99, 103, 117,
        123, 125, 129, 130
    ]
    cpp_lecture_order = [
        134, 136, 138, 141, 169, 172, 173, 188, 197, 198, 202, 203, 204, 209, 210,
        211, 213, 215, 217, 218, 219, 221, 222, 223, 224, 225, 227, 228
    ]
    c_lecture_order = [str(c) for c in c_lecture_order]
    cpp_lecture_order = [str(c) for c in cpp_lecture_order]
    for filename in os.listdir('./md'):
        file_id = filename[filename.rfind('_') + 1:filename.rfind('.')]
        if file_id not in c_lecture_order and file_id not in cpp_lecture_order:
            continue
        with open('./md/' + filename, 'r+') as f:
            content = f.read()
            f.seek(0, 0)
            content = content.split('\n')
            print(content[0])
            if '------' in content[0]:
                file_id = int(file_id)
                for i in range(max(len(c_lecture_order), len(cpp_lecture_order))):
                    print(i, file_id)
                    if i < len(c_lecture_order) - 1 and str(file_id) == c_lecture_order[i]:
                        next_val = c_lecture_order[i + 1]
                        content.insert(3, 'next_file : {0}'.format(next_val))
                        print("added")
                        break
                    elif i < len(
                            cpp_lecture_order) - 1 and str(file_id) == cpp_lecture_order[i]:
                        next_val = cpp_lecture_order[i + 1]
                        content.insert(3, 'next_file : {0}'.format(next_val))
                        break
                f.write('\n'.join(content))
