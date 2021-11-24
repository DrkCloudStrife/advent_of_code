import re

class PasswordValidator(object):
    POLICY_PARSER = '^(\d-\d)\s(\w):\s(.*)'

    def __init__(self, data):
        self.passwords = []
        self.valid_passwords = []

        for row in data:
            self.passwords.append(row)
        data.close()

    def validate(self):
        for policy in self.passwords:
            p_range, p_character, p_password, _ = self.__parse_policy(policy)
            print(p_range)
            print(p_character)
            print(p_password)
            print('=======')

    def __parse_policy(self, policy):
        results = re.split(self.POLICY_PARSER, policy)
        return self.__sanitize_policy_results(results)

    def __sanitize_policy_results(self, results):
        parsed_results = []
        for string in results:
            if (string != ""):
                parsed_results.append(string)

        return parsed_results
