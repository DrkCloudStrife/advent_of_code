import re

class PasswordValidator(object):
    POLICY_PARSER = '^(\d+-\d+)\s(\w):\s(.*)'

    def __init__(self, data):
        self.passwords = []
        self.valid_passwords = []

        for row in data:
            self.passwords.append(row)
        data.close()

    def validate(self):
        for policy in self.passwords:
            p_range, p_character, p_password = self.__parse_policy(policy)
            pattern = re.compile(r'{}'.format(p_character))
            range_arr = p_range.split('-')
            range_1 = range(int(range_arr[0]), int(range_arr[1]) + 1)
            if len(pattern.findall(p_password)) in range_1:
                self.valid_passwords.append(p_password)

    def __parse_policy(self, policy):
        results = re.findall(self.POLICY_PARSER, policy)
        return results[0]
