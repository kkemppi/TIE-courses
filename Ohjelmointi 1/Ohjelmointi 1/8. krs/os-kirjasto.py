import os

def fix_filenames(dir_path):
    content = os.listdir(dir_path)
    for file in content:
        if file.endswith(".mp3"):
            chars = list(file)
            try:
                int(chars[0])

                file_raw = file.strip(".mp3")
                file_split = file_raw.split("-")
                artist = file_split[1]
                song = file_split[2]
                new_filename = song + "-" + artist + ".mp3"
                os.rename(os.path.join(dir_path, file),
                          os.path.join(dir_path, new_filename))
            except:
                pass

