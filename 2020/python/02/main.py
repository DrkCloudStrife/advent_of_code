import re

class PasswordValidator(object):
    POLICY_PARSER = '^(\d+-\d+)\s(\w):\s(.*)'

    def __init__(self, data):
        self.passwords = []
        self.valid_passwords = []

        for row in data:
            self.passwords.append(row)

        data.close()

    def validate_pt1(self):
        if len(self.valid_passwords) != 0:
            self.__reset_valid_passwords()

        for policy in self.passwords:
            p_range, p_character, p_password = self.__parse_policy(policy)
            pattern = re.compile(r'{}'.format(p_character))
            range_arr = [int(n) for n in p_range.split('-')]
            range_1 = range(range_arr[0], range_arr[1] + 1)

            if len(pattern.findall(p_password)) in range_1:
                self.valid_passwords.append(p_password)

    def validate_pt2(self):
        if len(self.valid_passwords) != 0:
            self.__reset_valid_passwords()

        for policy in self.passwords:
            p_range, p_character, p_password = self.__parse_policy(policy)
            idx_1, idx_2 = [int(n) for n in p_range.split('-')]
            char_1 = p_password[idx_1-1]
            char_2 = p_password[idx_2-1]
            if char_1 == char_2 or p_character not in [char_1, char_2]:
                continue

            self.valid_passwords.append(p_password)

    def __parse_policy(self, policy):
        results = re.findall(self.POLICY_PARSER, policy)
        return results[0]

    def __reset_valid_passwords(self):
        self.valid_passwords = []
